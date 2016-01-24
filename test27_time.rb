require 'benchmark'

result = Benchmark.realtime do
  num = 0
  while num < 1000000 do
    str = "Desktop/abc.xlsx"
    str = str.gsub(/\w*\.(xlsx|csv)/, '[0]')
    num = num + 1
  end
end
puts "#{result}s"
