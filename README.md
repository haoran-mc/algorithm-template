# ACM template

## Introduction

I am a NCU ACMer. Ofter I need to compete with algorithm template. Although there are many templates available online, but only the template you write works best for you.

These templates are collected by myself and mark the origin of the topic. You can use `./11-构建LaTeX/main.py` this file to compile these templates into pdf file.

## Attention

As LaTeX only supports the highest four levels of headings, do not exceed four layers of directory edpth.

## Quick start

### Clone my repository

```shell
git clone https://github.com/haoran-mc/ACMtemplate.git
```

### Install the fonts

* English font : Consolas
* Chinese font : FandolSong

```shell
cd ./ACMtemplate/11-构建LaTeX/.fonts/
cp ./* /usr/share/fonts/
mkfontscale
mkfontdir
fc-cache
```

### Make for generating pdf file

```shell
cd ..
make
```
