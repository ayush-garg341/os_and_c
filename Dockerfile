From ubuntu:16.04
RUN mkdir -p /usr/src/app
WORKDIR /usr/src/app
RUN apt-get update && \
    apt-get -y install gcc mono-mcs make && \
    rm -rf /var/lib/apt/lists/*
COPY c_codes/ /usr/src/app
