/*******************************************************************************
 * Copyright 2015 See AUTHORS file.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ******************************************************************************/

package com.anonim.impossiblemission.test;

import static org.junit.Assert.assertTrue;

import org.junit.Ignore;
import org.junit.Test;
import org.junit.runner.RunWith;

import com.badlogic.gdx.Gdx;

import com.anonim.impossiblemission.GdxTestRunner;

@Ignore
@RunWith(GdxTestRunner.class)
public class AssetTests {

	@Test
	public void gamePackExists() {
		assertTrue("Will pass if game.pack file exist.", Gdx.files.internal("images/game.pack").exists());
	}

	@Test
	public void gameImageExists() {
		assertTrue("Will pass if game.png exist.", Gdx.files.internal("images/game.png").exists());
	}

	@Test
	public void loadingPackExists() {
		assertTrue("Will pass if loading.pack exists.", Gdx.files.internal("images/loading.pack").exists());
	}

	@Test
	public void loadingImageExists() {
		assertTrue("Will pass if loading.png exists.", Gdx.files.internal("images/loading.png").exists());
	}

	@Test
	public void skinFontExists() {
		assertTrue("Will pass if skin font file exists.", Gdx.files.internal("skin/commodore-64.fnt").exists());
	}

	@Test
	public void skinAtlasExists() {
		assertTrue("Will pass if uiskin.atlas exists.", Gdx.files.internal("skin/uiskin.atlas").exists());
	}

	@Test
	public void skinJsonExists() {
		assertTrue("Will pass if uiskin.json exists.", Gdx.files.internal("skin/uiskin.json").exists());
	}

	@Test
	public void skinImageExists() {
		assertTrue("Will pass if uiskin.png exists.", Gdx.files.internal("skin/uiskin.png").exists());
	}

	@Test
	public void databaseFileExsists() {
		assertTrue("Will pass if database.json exists.", Gdx.files.internal("database.json").exists());
	}
}
