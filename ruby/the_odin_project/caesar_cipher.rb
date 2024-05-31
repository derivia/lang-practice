def caesar_cipher(string, offset)
  return string if offset == 0
  # transforms the string on an array of unicode codes
  string.codepoints.map do |codechar|
    # checks if between a-z
    if codechar.between?(65, 90)
      ((codechar - 65 + offset) % 26 + 65).chr
    # checks if between A-Z
    elsif codechar.between?(97, 122)
      ((codechar - 97 + offset) % 26 + 97).chr
    # not between a-z or A-Z (e.g: "!" or "?")
    else
      codechar.chr
    end
  # &:chr is the same as { |x| x.chr }
  end.collect(&:chr).join
end

p caesar_cipher("hello!", 20)
