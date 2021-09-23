readelf -sW ../../Bin/Linux/Nominax | awk '$4 == "OBJECT" { print }' | sort -k 3 -n -r | head -n 50 | c++filt
