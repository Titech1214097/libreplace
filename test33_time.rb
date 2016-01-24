require 'benchmark'

result = Benchmark.realtime do
  num = 0
  while num < 1000000 do
    str = "printf(\"abc\"); //Out"
    str = str.gsub(/(.*;) ?(\/\/.*)/, '\2\n\1')
    num = num + 1
  end
end
puts "#{result}s"
