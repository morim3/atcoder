# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.134.0/containers/cpp/.devcontainer/base.Dockerfile
FROM debian

ARG DEBIAN_FRONTEND=noninteractive
# タイムゾーンを日本に設定
ENV TZ=Asia/Tokyo

RUN apt update && \
    apt install --no-install-recommends -y zsh time tzdata tree git curl

RUN chsh -s /bin/zsh

RUN apt update && \
    apt install  --no-install-recommends -y gcc-9 g++-9 gdb python3 python3-pip pypy3 nodejs npm

RUN git clone https://github.com/atcoder/ac-library.git /lib/ac-library
ENV CPLUS_INCLUDE_PATH /lib/ac-library

RUN pip install online-judge-tools==11.3.0

RUN curl -OL https://github.com/neovim/neovim/releases/download/v0.6.1/nvim-linux64.tar.gz &&\
    tar xzvf nvim-linux64.tar.gz && mv ./nvim-linux64/bin/nvim /usr/bin/ && rm nvim-linux64.tar.gz
ENV XDG_CONFIG_HOME /workspace


WORKDIR /workspace

# [Optional] Uncomment this section to install additional packages.
# RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
#     && apt-get -y install --no-install-recommends <your-package-list-here>