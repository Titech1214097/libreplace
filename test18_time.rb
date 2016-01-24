require 'benchmark'

result = Benchmark.realtime do
  num = 0
  while num < 1000000 do
    str = "abcdef"
    str = str.sub(/^def/, 'DEF')
    num = num + 1
  end
end
puts "#{result}s"
