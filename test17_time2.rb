require 'benchmark'

result = Benchmark.realtime do
  num = 0
  str = "abcababc"
  while num < 1000000 do
    str.match(/((ab)+c)+/)
    num = num + 1
  end
end
puts "#{result}s"
