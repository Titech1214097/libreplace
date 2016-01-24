require 'benchmark'

result = Benchmark.realtime do
  num = 0
  while num < 1000000 do
    str = "hello, world"
    str =  str.sub(/\w+/, '*\&*')
    num = num + 1
  end
end
puts "#{result}s"
