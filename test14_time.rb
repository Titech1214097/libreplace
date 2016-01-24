require 'benchmark'

result = Benchmark.realtime do
  num = 0
  while num < 1000000 do
    str = "My number is 0120-345-6789 !"
    str = str.gsub(/\d{2,5}-\d{1,4}-\d{4}/, 'TEL')
    num = num + 1
  end
end
puts "#{result}s"
