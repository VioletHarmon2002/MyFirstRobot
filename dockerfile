FROM ubuntu

ENV TZ=Europe/Amsterdam
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt update && \
    apt install -y apache2 apache2-utils libapache2-mod-php php-cli php-sockets && \
    apt clean

COPY ../web/ /var/www/html/
COPY startup.sh /usr/local/bin/start.sh

RUN chown -R www-data:www-data /var/www/html && \
    chmod -R 775 /var/www/html && \
    chmod +x /usr/local/bin/start.sh


EXPOSE 80
EXPOSE 8080


ENTRYPOINT ["apache2ctl", "-D", "FOREGROUND"]
