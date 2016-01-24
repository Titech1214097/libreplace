require 'benchmark'

result = Benchmark.realtime do
  num = 0
  while num < 1000000 do
    str = "abcdefghijklmnopqrstu"
    str = str.gsub(/xyz/, 'XYZ')
    num = num + 1
  end
end
puts "#{result}s"
