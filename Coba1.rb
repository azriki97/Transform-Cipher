# Fungsi untuk enkripsi pesan
def pesan_enkripsi(key, pesan)
  panjang_pesan = pesan.length
  jlh_baris = (panjang_pesan.to_f / key).ceil
  num_shaded_boxes = (jlh_baris * key) - panjang_pesan
  cipher_text = Array.new(key) { '' }

  kolom = 0
  baris = 0

  for i in 0...panjang_pesan
    cipher_text[kolom] << pesan[i]
    kolom += 1

    if (kolom == key) || (kolom == key - 1 && baris >= jlh_baris - num_shaded_boxes)
      kolom = 0
      baris += 1
    end
  end

  cipher_text.join
end

# Fungsi untuk dekripsi pesan
def pesan_dekripsi(key, pesan)
  panjang_pesan = pesan.length
  jlh_baris = (panjang_pesan.to_f / key).ceil
  num_shaded_boxes = (jlh_baris * key) - panjang_pesan
  plain_text = Array.new(jlh_baris) { '' }

  kolom = 0
  baris = 0

  for i in 0...panjang_pesan
    plain_text[baris] << pesan[i]
    kolom += 1

    if (kolom == jlh_baris) || (kolom == jlh_baris - 1 && baris >= key - num_shaded_boxes)
      kolom = 0
      baris += 1
    end
  end

  plain_text.join
end

print 'Masukkan kata-kata: '
pesan = gets.chomp

print "Masukkan key [2-#{pesan.length - 1}]: "
key = gets.to_i

puts "Enkripsi: #{pesan_enkripsi(key, pesan)}"
puts "Dekripsi: #{pesan_dekripsi(key, pesan)}"
