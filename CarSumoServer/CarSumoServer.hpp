enum ECatControlType
{
	ESCT_Human,
	ESCT_AI
};

class CarSumoServer : public CarSumo
{
public:
	static GameObjectPtr	StaticCreate() { return NetworkManagerServer::sInstance->RegisterAndReturn(new CarSumoServer()); }
	virtual void HandleDying() override;

	virtual void Update() override;

	void SetCatControlType(ECatControlType inCatControlType) { mCatControlType = inCatControlType; }

	void TakeDamage(int inDamagingPlayerId);

protected:
	CarSumoServer();

private:

	void HandleShooting();

	ECatControlType	mCatControlType;


	float		mTimeOfNextShot;
	float		mTimeBetweenShots;

};

