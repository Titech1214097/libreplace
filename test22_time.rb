require 'benchmark'

result = Benchmark.realtime do
  num = 0
  while num < 1000000 do
    str = "My IP is 192.168.1.333"
    str = str.gsub(/192\.168\.1\..{0,3}/, '[\0]')
    num = num + 1
  end
end
puts "#{result}s"
