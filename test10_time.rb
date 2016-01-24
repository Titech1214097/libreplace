require 'benchmark'

result = Benchmark.realtime do
  num = 0
  while num < 1000000 do
    str = "abc\n\n\n\ndef" 
    str = str.gsub(/\n+/, '\n')
    num = num + 1
  end
end
puts "#{result}s"
