require 'benchmark'

result = Benchmark.realtime do
  num = 0
  while num < 1000000 do
    str = "aone four twoa"
    str = str.gsub(/\s(one|two|three|four|five)\s/, ' N ')
    num = num + 1
  end
end
puts "#{result}s"
