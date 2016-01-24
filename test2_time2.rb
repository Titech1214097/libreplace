require 'benchmark'

result = Benchmark.realtime do
  num = 0
  str = "_Ruby_ is _cool_"
  while num < 1000000 do
    str.match(/_(.*?)_/)
    num = num + 1
  end
end
puts "#{result}s"
