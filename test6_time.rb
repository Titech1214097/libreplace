require 'benchmark'

result = Benchmark.realtime do
  num = 0
  while num < 1000000 do
    str = "Abc-ABC-AbC-abc" 
    str =  str.gsub(/abc/i, '[\0]')
    num = num + 1
  end
end
puts "#{result}s"
