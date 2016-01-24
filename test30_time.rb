# coding: utf-8
require 'benchmark'

result = Benchmark.realtime do
  num = 0
  while num < 1000000 do
    str = "あいうえあああいうえ"
    str = str.gsub(/(あ){1,5}/, '[\0]')
    num = num + 1
  end
end
puts "#{result}s"
