def sub_strings(string, dictionary)
  # avoid dealing with uppercase
  string_lowered = string.downcase
  # creates a hash with keys being words from dictionary 
  # and values being the count of each word appearance of the string
  dictionary.inject(Hash.new(0)) do |words, word|
    # variable based on how big the resulting array is
    matches = string_lowered.scan(word).length
    # adds it to the hash if matches > 0
    words[word] += matches unless matches == 0
    # returns words for the next iteration
    words
  # the "end" is where the function returns the final value
  # which i would like to sort by count in descending order
  end.sort_by { |_, count| count }.reverse.to_h
end


dictionary = ["below","down","go","going","horn","how","howdy","it","i","low","own","part","partner","sit"]
p sub_strings("Howdy partner, sit down! How's it going?", dictionary)
