FROM gcc:8

RUN wget https://github.com/Kitware/CMake/releases/download/v3.14.3/cmake-3.14.3-Linux-x86_64.sh \
      -q -O /tmp/cmake-install.sh \
      && chmod u+x /tmp/cmake-install.sh \
      && mkdir /usr/bin/cmake \
      && /tmp/cmake-install.sh --skip-license \
      && rm /tmp/cmake-install.sh \
      && wget  https://sourceware.org/pub/valgrind/valgrind-3.15.0.tar.bz2 \
      -q -O /tmp/valgrind-3.15.0.tar.bz2 \
      && cd tmp \
      && tar -xvf valgrind-3.15.0.tar.bz2 \
      && cd valgrind-3.15.0 \
      && ./configure \
      && make \
      && make install \
      && rm -rf /tmp/valgrind*