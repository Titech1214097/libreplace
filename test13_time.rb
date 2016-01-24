require 'benchmark'

result = Benchmark.realtime do
  num = 0
  while num < 1000000 do
    str = "aaa\\()*+?.aaa"
    str = str.gsub(/\\\(\)\*\+\?\./, '[\0]')
    num = num + 1
  end
end
puts "#{result}s"
