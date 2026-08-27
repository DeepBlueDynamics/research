# Static site for the APNT console demo (Cloud Run).
# NOTE: this is the PUBLIC demo image — NOT the air-gapped Iron Bank build
# required for the Phase I deliverable. Kept deliberately separate.
FROM nginx:alpine
COPY nginx.conf /etc/nginx/conf.d/default.conf
COPY index.html /usr/share/nginx/html/index.html
COPY og-card.png /usr/share/nginx/html/og-card.png
EXPOSE 8080
