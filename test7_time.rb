require 'benchmark'

result = Benchmark.realtime do
  num = 0
  while num < 1000000 do
    str = "i = false; j = true;" 
    str = str.gsub(/true|false/, 'bool')
    num = num + 1
  end
end
puts "#{result}s"
