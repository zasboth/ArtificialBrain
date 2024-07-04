FROM ubuntu:latest


ARG U_USER
ARG U_GID
ARG U_UID

RUN apt update
RUN apt upgrade -y
RUN apt-get install -y git vim nano sudo adduser mc
RUN apt-get install -y gcc
RUN apt-get install -y g++
RUN apt-get install -y build-essential cmake bash-completion cmake-extras

RUN addgroup --gid $U_GID $U_USER
RUN adduser --uid $U_UID --gid $U_GID --disabled-password --gecos "" $U_USER
#RUN echo "$U_USER ALL=(ALL) NOPASSWD: ALL" >> /etc/sudoers
RUN echo "$U_USER ALL=(ALL:ALL) NOPASSWD: ALL" >> /etc/sudoers.d/$U_USER

SHELL [ "/bin/bash" ]