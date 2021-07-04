(TeX-add-style-hook
 "template"
 (lambda ()
   (TeX-add-to-alist 'LaTeX-provided-class-options
                     '(("article" "10pt" "a4paper")))
   (TeX-add-to-alist 'LaTeX-provided-package-options
                     '(("hyperref" "breaklinks" "colorlinks" "linkcolor=black" "citecolor=black" "urlcolor=black") ("fncychap" "Glenn")))
   (add-to-list 'LaTeX-verbatim-environments-local "lstlisting")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "path")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "url")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "nolinkurl")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "hyperbaseurl")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "hyperimage")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "hyperref")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "lstinline")
   (add-to-list 'LaTeX-verbatim-macros-with-delims-local "path")
   (add-to-list 'LaTeX-verbatim-macros-with-delims-local "lstinline")
   (TeX-run-style-hooks
    "latex2e"
    "article"
    "art10"
    "titletoc"
    "titlesec"
    "abstract"
    "xeCJK"
    "amsmath"
    "amsthm"
    "listings"
    "xcolor"
    "geometry"
    "fontspec"
    "graphicx"
    "setspace"
    "fancyhdr"
    "hyperref"
    "fncychap"
    "color"
    "verbatim")
   (TeX-add-symbols
    "HRule")
   (LaTeX-add-xcolor-definecolors
    "dkgreen"
    "gray"
    "mauve"))
 :latex)

