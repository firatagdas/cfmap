package com.cf.map;

import android.app.Activity;

import java.lang.Override;
import java.lang.Runnable;
import java.lang.String;
import java.util.concurrent.Semaphore;

import android.util.Log;
import com.google.android.gms.common.ConnectionResult;
import com.google.android.gms.common.GooglePlayServicesUtil;
import com.google.android.gms.maps.GoogleMap;
import com.google.android.gms.maps.GoogleMapOptions;
import com.google.android.gms.maps.MapFragment;
import com.google.android.gms.maps.MapView;
import com.google.android.gms.maps.MapsInitializer;
import com.google.android.gms.maps.OnMapReadyCallback;

public class CFAndroidMapController
{
    private final String TAG = "CFAndroidMapController";

    private final Activity m_activity;
    private final long m_id;
    private GoogleMap m_mapController;
    private MapView m_mapView;

    public CFAndroidMapController(final Activity activity, final long id)
    {
        m_activity = activity;
        m_id = id;

        final CFAndroidMapController closure = this;

        final Semaphore sem = new Semaphore(0);
        m_activity.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                boolean gotError = false;
                try {
                    MapsInitializer.initialize(m_activity);
                } catch (Exception e) {
                    e.printStackTrace();
                    gotError = true;
                }

                if (!gotError) {
                    int playServiceStatus = GooglePlayServicesUtil.isGooglePlayServicesAvailable(m_activity);
                    if (playServiceStatus != ConnectionResult.SUCCESS) {
                        Log.d(TAG, "Google Play Service Error: " + GooglePlayServicesUtil.getErrorString(playServiceStatus));
                        gotError = true;
                    }
                }

                if (!gotError) {
                    GoogleMapOptions options = new GoogleMapOptions();
                    m_mapView = new MapView(m_activity, options);
                    m_mapView.onCreate(null);
                    m_mapView.onResume();

                    m_mapController = m_mapView.getMap();

                    Log.d(TAG, "MapView: " + (m_mapController != null ? "CONTROLLER: YES" : "CONTROLLER: NO") + " -> " + (m_mapView != null ? "VIEW: YES" : "VIEW: NO"));
                }

                sem.release();
            }
        });

        try {
            sem.acquire();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public MapView getMapView() {
        return m_mapView;
    }

    public GoogleMap getMapController() {
        return m_mapController;
    }
}
