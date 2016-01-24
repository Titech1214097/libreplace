require 'benchmark'

result = Benchmark.realtime do
  num = 0
  while num < 1000000 do
    str = "hello,\nworld\r\n"
    str = str.gsub(/(\r\n|\r|\n)/, "<br />")
    num = num + 1
  end
end
puts "#{result}s"

