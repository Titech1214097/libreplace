require 'benchmark'

result = Benchmark.realtime do
  num = 0
  while num < 1000000 do
    str = "password"
    str = str.gsub(/\w{4,16}"/, '*********')
    num = num + 1
  end
end
puts "#{result}s"
