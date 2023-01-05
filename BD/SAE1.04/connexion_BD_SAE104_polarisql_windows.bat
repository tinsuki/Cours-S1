::--------------------------------------------------------------------
:: A modifier
:: Pas d'espace entre la variable, le signe = et la valeur
::--------------------------------------------------------------------
@echo off
:: Nom utilisateur (login ULR : même que la BD INFO1 à l'IUT)
set USER=ksimon

:: Mot de passe utilisateur (même que la BD INFO1 à l'IUT)
set USER_PWD=x5xvdpq28r

:: Chemin absolu vers le dossier décomprimé
:: exemple : 
:: SQLPLUS_PATH=\\qi\jmalki01\Windows\Bureau\Oracle-Windows-InstantClient_12_1
set SQLPLUS_PATH="C:\Program Files\Oracle-Windows-InstantClient_12_1"

::--------------------------------------------------------------------
:: Ne pas modifier
::--------------------------------------------------------------------
set HOST=193.48.38.244
set PORT=80
set BD=SAE104
"%SQLPLUS_PATH%\sqlplus.exe" %USER%/%USER_PWD%@%HOST%:%PORT%/%BD%
@echo on