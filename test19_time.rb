require 'benchmark'

result = Benchmark.realtime do
  num = 0
  while num < 1000000 do
    str = "I get two stock tips"
    str = str.gsub(/stock\\s*tips?/, '[\\0]')
    num = num + 1
  end
end
puts "#{result}s"
