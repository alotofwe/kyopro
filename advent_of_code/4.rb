require 'digest/md5'
N = 10000000

def solve key
  N.times do |t|
    md5 = Digest::MD5.hexdigest("#{key}#{t.to_s}")
    return t if md5[0, 5] == "00000"
  end
  return "error"
end

puts solve('ckczppom')
