FROM debian:stable-slim

# Met à jour les paquets et installe Apache + PHP
RUN apt-get update && apt-get install -y \
    apache2 \
    php libapache2-mod-php php-sqlite3 \
    unzip git composer \
    && apt clean \
    && rm -rf /var/lib/apt/lists/*

# Expose le port HTTP
EXPOSE 80

# Lance Apache en mode foreground
CMD ["apachectl", "-D", "FOREGROUND"]
