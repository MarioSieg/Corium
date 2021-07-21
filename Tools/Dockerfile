FROM ubuntu

RUN apt-get update
RUN apt-get install -y software-properties-common
RUN add-apt-repository ppa:ubuntu-toolchain-r/test
RUN apt-get update
RUN apt-get install -y gcc-11 g++-11
RUN LD_LIBRARY_PATH=/usr/local/lib64/:$LD_LIBRARY_PATH
RUN export LD_LIBRARY_PATH
RUN apt-get install -y valgrind

WORKDIR /corium
COPY CoriumC .
COPY main.cor .
RUN chmod +x CoriumC
CMD ["./CoriumC"]

