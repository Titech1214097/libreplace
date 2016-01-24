require 'benchmark'

result = Benchmark.realtime do
  num = 0
  str = "http://abc.def.com/ghi"
  while num < 1000000 do
    str.match(/(http://)(.*?)\/(.*)"/)
    num = num + 1
  end
end
puts "#{result}s"
