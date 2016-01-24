require 'benchmark'

result = Benchmark.realtime do
  num = 0
  while num < 1000000 do
    str = "top = REGEX"
    str = str.gsub(/(\w*)\s?=\s?(\w*)/, '<\1>\2</\1>')
    num = num + 1
  end
end
puts "#{result}s"
