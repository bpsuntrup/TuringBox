STATE = 0 # Initial State

# state, symbol,  new state, write,  move
# new state == None => halt
# move is a signed integer
# int(0) is default symbol
PROGRAM = [
    (0,0,1,1,0),
    (1,1,2,1,1),
    (2,0,None,2,0)
]

TAPE = []
HEAD = 0

# transform program
_program = {}
for instruction in PROGRAM:
    if not instruction[0] in _program.keys():
        _program[instruction[0]] = {}
    _program[instruction[0]][instruction[1]] = {
        'state': instruction[2],
        'write': instruction[3],
        'move': instruction[4],
    }

class TuringException(Exception): pass

while True:
    while HEAD >= len(TAPE):
        TAPE.append(0)
    while HEAD < 0:
        TAPE = [0] + TAPE
        HEAD += 1

    symbol = TAPE[HEAD]
    try:
        move = _program[STATE][symbol]['move']
        write = _program[STATE][symbol]['write']
        new_state = _program[STATE][symbol]['state']
    except KeyError:
        raise TuringException('Undefined state/symbol combination: {}/{}'.format(STATE, symbol))

    TAPE[HEAD] = write
    HEAD += move

    for i in range(len(TAPE)):
        if i == HEAD:
            print '>>',
        print TAPE[i],
    print ''

    if new_state is None:
        print("Output: {}".format(TAPE))
        break
    else:
        STATE = new_state
