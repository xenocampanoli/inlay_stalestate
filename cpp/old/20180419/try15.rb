#!/usr/bin/ruby

s = "^^^1234^^^"

puts "trace s:  #{s}"

if s =~ /^^^^[^^]*^^^$/ then
	puts "No way."
end
if s =~ /^\^\^\^[^^]*\^\^\^$/ then
	puts "Hmm.  Okay, that is reasonable coming from Ruby, but I am surprised."
end
if s =~ /^\^\^\^[^\^]*\^\^\^$/ then
	puts "Now that is what I was expecting."
end
