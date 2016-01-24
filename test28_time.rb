require 'benchmark'

result = Benchmark.realtime do
  num = 0
  while num < 1000000 do
    str = "aaabbbcabcabb"
    str = str.gsub(/(ab[^c]|a[^b]|[^a])+$/, '[\0]')
    num = num + 1
  end
end
puts "#{result}s"
