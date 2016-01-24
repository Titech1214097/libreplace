require 'benchmark'

result = Benchmark.realtime do
  num = 0
  while num < 1000000 do
    str = "abcababc"
    str = str.sub(/[((ab)+c)+]/, '[\1]')
    num = num + 1
  end
end
puts "#{result}s"
