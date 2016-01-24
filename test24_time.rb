# coding: utf-8
require 'benchmark'

result = Benchmark.realtime do
  num = 0
  while num < 1000000 do
    str = "私は2015-11-10に帰宅"
    str = str.gsub(/(\d{1,4})[\/-](\d{1,2})[\/-](\d{1,2})/, '\1年\2月\3日')
    num = num + 1
  end
end
puts "#{result}s"
