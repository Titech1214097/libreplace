require 'benchmark'

result = Benchmark.realtime do
  num = 0
  while num < 1000000 do
    str = "http://abc.def.com/ghi" 
    str = str.sub(/(http:\/\/)(.*?)\/(.*)/, 'path = \+')
    num = num + 1
  end
end
puts "#{result}s"
