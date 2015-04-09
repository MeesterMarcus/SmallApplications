1i\
\\documentstyle[11pt]{article} \
\\begin{document}

1i\
\\begin{center} {\\bf 

s/\\/\\verb\+\\\+/g
s/%/\\%/g
s/\^/\\\^/g
s/--/-\\hspace\{.01cm\}-/g

s/^+/ \\\\/
s/^-/ \\\\/

s/^\([A-Z]\)\+$/\\item\[&\] \\hfill \\\\/

1a\
\} \\end{center}


2i\
\\begin{description}

$a\
\\end{description}

$a\
\\end{document}



