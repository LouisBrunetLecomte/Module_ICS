<!doctype html>
<html lang="en-US">
    <head>
        <meta charset="UTF-8">
        <title>Formulaire</title>
        <style></style>
        <script></script>
    </head>
    <body><?php
        if (empty($_POST)) { ?>

        <form method="POST">
            <p>
                <label for="name">Nom :</label>
                <input type="text" name="name" id="name">
            </p>
            <input type="submit" name="Valider">
        </form><?php
        } else { ?>

        <p>Formulaire soumis ! Merci !</p>
        <p><a href="">Retour</a></p><?php
        } ?>
    </body>
</html>

