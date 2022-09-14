import times

const
  repeats: int = 5
  timesToIterate: int64 = 1000000000

var
  timesTook: array[repeats, float]

for c in 0..(repeats - 1):
  timesTook[c] = cpuTime()
  var
    i: int64 = 0
  while i < timesToIterate:
    stdout.write('-')
    i += 1
  timesTook[c] = cpuTime() - timesTook[c]

var
  time_avg: float = 0
for c in 0..(repeats - 1):
  time_avg += timesTook[c]

echo(time_avg / (float)repeats)
