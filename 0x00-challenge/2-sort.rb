result = []
ARGV.each do |arg|
  # Skip if not an integer
  next if arg !~ /^-?[0-9]+$/
  
  # Convert to integer
  i_arg = arg.to_i
  
  # Initialize the insertion flag
  is_inserted = false

  # Iterate to find the correct insert position
  result.each_with_index do |item, index|
    if i_arg <= item
      result.insert(index, i_arg)
      is_inserted = true
      break
    end
  end

  # Append to the end if it wasn't inserted (it's the largest element so far)
  result << i_arg unless is_inserted
end

puts result
