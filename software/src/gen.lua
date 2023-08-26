for i = 1,7,1 do
	for j = 1,10,1 do
		io.write(string.format("0x%02x", math.random(255)))
		if i < 7 or j < 10 then
			io.write(",")
		end
	end
	io.write("\n")
end