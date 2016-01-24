require 'benchmark'

result = Benchmark.realtime do
  num = 0
  while num < 1000000 do
    str = "_Ruby_ is _cool_." 
    str =  str.gsub(/_(.+?)_/, '<em>\1</em>')
    num = num + 1
  end
end
puts "#{result}s"
