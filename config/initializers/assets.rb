# Be sure to restart your server when you modify this file.

# Version of your assets, change this if you want to expire all your assets.
Rails.application.config.assets.version = '1.0'

# Add additional assets to the asset load path.
# Rails.application.config.assets.paths << Emoji.images_path
# Add Yarn node_modules folder to the asset load path.
Rails.application.config.assets.paths << Rails.root.join('node_modules')

# Precompile additional assets.
# application.js, application.css, and all non-JS/CSS in app/assets
# folder are already added.
Rails.application.config.assets.precompile += %w[
  application_v2.css
  active_admin.css
  application_v2.js
  active_admin.js
  mailer.css
  mailer_v2.css
  video-js.swf vjs.eot vjs.svg vjs.ttf vjs.woff
  v2/completion_certificate.css
  v2/application_certificate.css
]
