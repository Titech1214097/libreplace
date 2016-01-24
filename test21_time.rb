require 'benchmark'

result = Benchmark.realtime do
  num = 0
  while num < 1000000 do
    str = "vi@gra v1agra v1@gra v!@gra"
    str = str.gsub(/v[i!1][a@]gr[a@]/, 'viagra')
    num = num + 1
  end
end
puts "#{result}s"
