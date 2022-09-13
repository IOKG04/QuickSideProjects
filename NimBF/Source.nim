import os
import terminal

if paramCount() < 1:
  echo("ERROR: NOT ENOUGH ARGUMENTS");
  quit(1)

let
  program: string = readFile(paramStr(1))

# echo(program)

var
  pc: int = 0                   # program counter
  cells: seq[int] = @[0]        # memory cells
  p_cell: int = 0               # pointer to current memory cell
  prevBrackets: seq[int] = @[0] # position of previous brackets
  bracketCount: int = 0         # amount of brackets

# echo(cells[0])
# echo(cells[3])

while pc < program.len:
  # loop
  case program[pc]
  of '+':
    cells[p_cell] += 1
  of '-':
    cells[p_cell] -= 1
  of '>':
    p_cell += 1
    if p_cell >= cells.len:
      cells.add(0)
  of '<':
    p_cell -= 1
    if p_cell < 0:
      echo("ERROR: CELL POINTER GOT BELOW ZERO AT ", pc)
      quit(1)
  of '[':
    bracketCount += 1
    prevBrackets.add(pc)
    if cells[p_cell] == 0:
      var current_bc: int = bracketCount + 1
      while program[pc] != ']' and bracketCount != current_bc:
        pc += 1
        if program[pc] == '[':
          bracketCount += 1
        elif program[pc] == ']':
          bracketCount -= 1
  of ']':
    bracketCount -= 1
    pc = prevBrackets.pop() - 1
  of '.':
    stdout.write(char(cells[p_cell]))
    # echo(char(cells[p_cell]))
  of ',':
    var ch: char = getch()
    stdout.write(ch)
    cells[p_cell] = ord(ch)
  else:
    pc += 0
  pc += 1

quit(0)
