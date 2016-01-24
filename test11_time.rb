require 'benchmark'

result = Benchmark.realtime do
  num = 0
  while num < 1000000 do
    str = "abc\ndef\nghijk\nlmn\n"
    str = str.gsub(/.*\n/, '>\0')
    num = num + 1
  end
end
puts "#{result}s"
