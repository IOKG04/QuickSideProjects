import times

const
  repeats: int = 5
  timesToIterate: int64 = 10000000000

var
  timesTook: array[repeats, float]

for c in 0..(repeats - 1):
  timesTook[c] = cpuTime()
  var
    r: uint64 = 0
    i: int64 = 0
  while i < timesToIterate:
    r += (uint64)i
    i += 1
  timesTook[c] = cpuTime() - timesTook[c]

var
  time_avg: float = 0
for c in 0..(repeats - 1):
  time_avg += timesTook[c]

echo(time_avg / (float)repeats)
