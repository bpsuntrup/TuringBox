#!/usr/bin/python
""" The following is a Turing machine with states that
communicate with one another using TCP/IP. An Instruction table
is identified with a unique hash, which allows the machine to run
several Turing programs concurrently. Right now only Turing machines
with up to 5 states are supported. """

import socket
import threading
from threading import Thread
import time

# Note that 0 is the init state

class InstructionTable(object):
    def __init__(self, instructions):
        """ instructions: list of 5-tuples of (state, symbol, state, write, move)
                          where state is 0 to 4, or None for special "halt" state,
                          symbol is any string
                          write is any string
                          move is 'left' or 'right' or None if no move is to be performed"""
        self.instructions = {}
        for instruction in instructions:
            self.instructions[instruction[0]] = {}
            self.instructions[instruction[0]][instruction[1]] = (instruction[2:5])

    def __repr__(self):
        return 'InstructionTable(' + str(self.instructions) + ')'

    def get_instruction(self, state, symbol):
        return self.instructions[state][symbol]

# There needs to be a data structure of InstructionTables, init Tapes, keyed
# with names
# Table of program names, along with tapes and instruction sets. Instruction
# set names MUST NOT END IN !
GRAND_TABLE = {
    'program1': {
        'program': InstructionTable([(0,'2',None,'3',None),]), # take 2 write 3, halt
        'tape': (['2',], 0)
    },
    'program2': {
        'program': InstructionTable([
            (0,'0',1,'0',None),
            (1,'0',None,'0',None),
        ]),
        'tape': (['0',],0)
    }
}

class StateServer(object):
    def __init__(self, state_number, instruction_sets=None):
        """ state_number must be integer, please
        instruction_sets must be a dictionary of InstructionTables keyed with
           names, or "hashes" """
        self.state_number = state_number
        self.port = 10000 + state_number
        self.instructions = {}
        if instruction_sets is not None:
            for key, val in instruction_sets.items():
                self.instructions[key] = val.instructions[self.state]
        self.server_thread = Thread(target=self.server, args=())
        self.server_thread.daemon = True
        self.server_thread.start()

    def start(self):
        global GRAND_TABLE
        if self.state_number == 0:
            for program in GRAND_TABLE:
                self.execution_client(program)

    def execution_client(self, instruction_set):
        """ Execute instruction passed for given hash and pass new instruction
        to next state """
        """ looks up symbol in instruction set passed to it"""

        global GRAND_TABLE
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

        tape, head = GRAND_TABLE[instruction_set]['tape']
        symbol = tape[head]
        state, write, move = GRAND_TABLE[instruction_set]['program'].get_instruction(self.state_number, symbol)
        tape[head] = write
        if move == 'right':
            head += 1
            if head >= len(tape):
                tape.append(0) # DEFAULT SYMBOL IS 0
        elif move == 'left':
            if head == 0:
               GRAND_TABLE[instruction_set] = [0] + tape
            else:
                head -= 1
        elif move is None:
            pass
        else:
            raise TapeError("move instructions must be left or right or None")

        # Halt
        if state is None:
            print (instruction_set + " halted. Output: ")
            print (tape)
        else:
            # port is 10,000 + state_number
            print 10000 + state
            s.connect(('127.0.0.1', 10000 + state))
            print instruction_set + '!'
            s.sendall(instruction_set + '!') # Note the special termination char
            ack = s.recv(3)
            print ack

    def server(self):
        print 'state: ' + str(self.state_number) + ' port: ' + str(self.port)
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.bind(('127.0.0.1',self.port))
        s.listen(10)
        print 'state {} listening'.format(self.state_number)
        while True:
            if self.state_number == 1:
                print 'state 1 listening'
            (clientsocket, address) = s.accept()
            print 'got socket {}'.format(clientsocket)
            # t = Thread(target=self.handle_client, args=(clientsocket,))
            # t.daemon = True
            # t.start()

#    def handle_client(self,clientsocket):
            print 'in handle_client'
            instruction_set = ''
            msg_char = ''
            while not msg_char == '!':
                print msg_char + " ; "
                msg_char = clientsocket.recv(1)
                instruction_set += msg_char
            print instruction_set
            clientsocket.sendall('ACK')
            t = Thread(target=self.execution_client, args=(self, instruction_set))
            t.daemon = True
            t.start()

State0 = StateServer(0)
State1 = StateServer(1)
State2 = StateServer(2)
State3 = StateServer(3)
State4 = StateServer(4)
State5 = StateServer(5)

time.sleep(1)

# State 0 is the unique start state.
State0.start()
